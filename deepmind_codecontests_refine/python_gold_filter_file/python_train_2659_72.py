import bisect
n,m = map(int, input().split( ))
listt = list(map(int, input().split( )))
listt.sort()
pos = bisect.bisect_right(listt,m)
if(pos == n):
    print(n)
else:
    print((n-pos)*2 + pos)