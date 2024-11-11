n,v = map(int, input().split())
req = n-1
req -= min(n-1,v)
result = min(n-1,v)

for i in range(2,n):
    if req>0:
        result += i
        req -= 1
    else:
        break
print(result)