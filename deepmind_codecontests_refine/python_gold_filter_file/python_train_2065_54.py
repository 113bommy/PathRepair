input()
A=list(map(int, input().split()))
n=0
while all(a%2==0 for a in A):
    A=[a/2 for a in A]
    n+=1
print(n)