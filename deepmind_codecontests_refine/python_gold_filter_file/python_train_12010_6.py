n = int( input().strip() )
arr = list( map(int, input().strip().split(' ')))
minv = 101
for i in arr:
    minv = min(i, minv)
for i in range(n):
    if arr[i] == minv:
        arr[i] = 101

minv = 101
for i in arr:
    minv = min(i, minv)
print( str(minv) if minv < 101 else 'NO' )