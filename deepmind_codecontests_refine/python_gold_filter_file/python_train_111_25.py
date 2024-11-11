n = int(input())
A = list(map(int, input().split()))
k = max(A)
s = sum(A)
while((k*n - s) <= s):
    k+=1
print(k)