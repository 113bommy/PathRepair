import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N = int(readline())
ABC = list(map(int,read().split()))
A = ABC[::3]; B = ABC[1::3]; C = ABC[2::3]

class BIT():
    def __init__(self, max_n):
        self.size = max_n + 1
        self.tree = [0] * self.size
        
    def get_sum(self,i):
        s = 0
        while i:
            s += self.tree[i]
            i -= i & -i
        return s
 
    def add(self, i, x):
        while i < self.size:
            self.tree[i] += x
            i += i & -i

def Inversion(seq):
    # seqは、1,2,...,Nの順列
    N = len(seq)
    bit = BIT(N)
    inv = N*(N-1)//2
    for x in seq:
        inv -= bit.get_sum(x)
        bit.add(x,1)
    return inv

def get_rank(seq):
    x_to_i = {x:i for i,x in enumerate(sorted(seq))}
    return [1+x_to_i[x] for x in seq]

def solve_x(A,B,C):
    M = (N*(N-1)//2+1)//2 # 必要な交点個数
    U = 2*10**8 + 100 # 交点の座標の上界
    left = -U # 交点の個数の合計が M 個に満たない
    right = U # 交点の個数の合計が M 個以上である
    # x = -inf における y の順序
    order = sorted(range(N),key = lambda i: A[i]/B[i])
    def test(x):
        y = [(C[i]-A[i]*x)/(B[i]) for i in order]
        seq = get_rank(y)
        return Inversion(seq) >= M
    
    for _ in range(60):
        mid = (left + right)/2
        if test(mid):
            right = mid
        else:
            left = mid
    return (left + right)/2

x = solve_x(A,B,C)
y = solve_x(B,A,C)
print(x,y)

