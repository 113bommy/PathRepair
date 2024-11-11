def main():
        N,Q = map(int,input().split())
        ab = [list(map(int,input().split())) for _ in range(N - 1)]
        ab.sort()
        
        plus = [0 for _ in range(N)]
        for _ in range(Q):
        	p,x = map(int,input().split())
        	plus[p - 1] += x 

        for a,b in ab:
                plus[b - 1] += plus[a - 1]
        print(*plus)

if __name__ == '__main__':
        main()