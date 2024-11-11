import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

from bisect import bisect_left

N,E,T = map(int,readline().split())
X = [0] + list(map(int,read().split()))

half = T//2
I = [bisect_left(X,x-half) for x in X]

INF = 10**18

def base_solution():
    # これをseg木に乗せまーす
    dp = [0] * (N+1)
    for n in range(1,N+1):
        x = X[n]
        i = I[n]
        # i-1番目まで戻る → 待ち時間なし
        # i番目まで戻る → 待ち時間発生
        if i >= 1:
            t1 = min((dp[k]-X[k] for k in range(i-1,n)),default=INF)+x+T
            t2 = min((dp[k]-X[k]-2*X[k+1] for k in range(i-1)),default=INF)+3*x
        else:
            t1 = min((dp[k]-X[k] for k in range(n)),default=INF)+x+T
            t2 = INF
        dp[n] = min(t1,t2)
    answer = dp[N] + (E-X[-1])
    print(answer)

class MinSegTree():
    def __init__(self,N):
        self.Nelem = N
        self.size = 1<<(N.bit_length()) # 葉の要素数
        
    def build(self,raw_data):
        # raw_data は 0-indexed
        INF = 10**18
        self.data = [INF] * (2*self.size)
        for i,x in enumerate(raw_data):
            self.data[self.size+i] = x
        for i in range(self.size-1,0,-1):
            x = self.data[i+i]; y = self.data[i+i+1]
            self.data[i] = x if x<y else y
    
    def update(self,i,x):
        i += self.size
        self.data[i] = x
        i >>= 1
        while i:
            x = self.data[i+i]; y = self.data[i+i+1]
            self.data[i] = x if x<y else y
            i >>= 1
    
    def get_value(self,L,R):
        # [L,R] に対する値を返す
        L += self.size
        R += self.size + 1
        # [L,R) に変更
        x = 10**18
        while L < R:
            if L&1:
                y = self.data[L]
                if x > y: x = y
                L += 1
                
            if R&1:
                R -= 1
                y = self.data[R]
                if x > y: x = y
            L >>= 1; R >>= 1
        return x

dp1 = MinSegTree(N+1) # dp[k]-X[k] を格納する
dp2 = MinSegTree(N+1) # dp[k]-X[k]-2X[k+1] を格納する
dp1.build([0]*(N+1))
dp2.build([0]*(N+1))
dp2.update(0,-2*X[1])
X.append(E)
for n in range(1,N+1):
    x = X[n]; i = I[n]
    if i >= 1:
        t1 = dp1.get_value(i-1,n-1)+x+T
        t2 = dp2.get_value(0,i-2)+3*x
        t = t1 if t1<t2 else t2
    else:
        t = dp1.get_value(0,n-1)+x+T
    dp1.update(n,t-x)
    dp2.update(n,t-x-2*X[n+1])
answer = t+E-x
print(answer)