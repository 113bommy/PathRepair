n , c = map(int,input().strip().split())
days = list(map(int, input().strip().split()))
arr = []
for i in range(n-1):
    arr.append(days[i]-days[i+1]-c)
if max(arr) < 0:
    print(0)
else:
    print(max(arr))