n = int(input())
if n%2==0:
    mid = n/2
else:
    mid = (n + 1)/2
print(int((mid + n)%(n+1)))