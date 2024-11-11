n, m = map(int, input().split())
count=0
for i in range(n):
    x = list(map(str, input().split()))
    if 'C' in x or 'M' in x or 'Y' in x:
        print('#Color')
        break
    else:
        count+=1
if count==n:
    print('#Black&White')