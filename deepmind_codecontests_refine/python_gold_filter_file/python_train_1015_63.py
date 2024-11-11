class SegmentTree():

    def __init__(self,N):
        # N: 処理する区間の長さ
        self.N0 = 2**(N-1).bit_length()
        self.INF = 2**31-1
        self.data = [self.INF]*(2*self.N0)
    # a_k の値を x に更新
    def update(self, k, x):
        k += self.N0-1
        self.data[k] = x
        while k >= 0:
            k = (k - 1) // 2
            self.data[k] = min(self.data[2*k+1], self.data[2*k+2])
    # 区間[l, r)の最小値
    def query(self, l, r):
        L = l + self.N0; R = r + self.N0
        s = self.INF
        while L < R:
            if R & 1:
                R -= 1
                s = min(s, self.data[R-1])

            if L & 1:
                s = min(s, self.data[L-1])
                L += 1
            L >>= 1; R >>= 1
        return s

def main():
    n,k = tuple([int(t)for t in input().split()])
    size = 3*10**5
    lst = SegmentTree(size+1)
    for _ in range(n):
        a = int(input())
        l,r = max(a-k,0),min(a+k+1,size+1)
        m = min(lst.query(l,r),0)
        lst.update(a,m-1)

    print(-lst.query(0,3*10**5))

if __name__ == "__main__":
    main()
