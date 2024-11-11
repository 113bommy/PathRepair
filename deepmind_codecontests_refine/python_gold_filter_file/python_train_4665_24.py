N=int(input())//2
D=sorted(list(map(int,input().split())))
print(D[N]-D[N-1])