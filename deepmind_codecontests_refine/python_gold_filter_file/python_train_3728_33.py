X,Y,Z,K = map(int,input().split())
*A, = map(int,input().split())
*B, = map(int,input().split())
*C, = map(int,input().split())
AB = sorted(a+b for a in A for b in B)[::-1][:K]
ABC = sorted(ab+c for ab in AB for c in C)[::-1][:K]
print(*ABC,sep="\n")