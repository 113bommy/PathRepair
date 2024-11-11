N=int(input())
A=list(map(int,input().split()))
B=[x for x in A if x%2==1]
print('YES' if len(B)%2==0 else 'NO')