N=int(input())
D=list(map(int,input().split()))
D.sort()

K=D[N//2]-D[N//2-1]

print(K)