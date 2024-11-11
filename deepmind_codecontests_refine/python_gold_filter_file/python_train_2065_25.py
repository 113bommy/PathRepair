input()
A=list(map(int, input().split()))
count=0
while all(a%2==0 for a in A):
    A=[i/2 for i in A]
    count+=1
print(count)