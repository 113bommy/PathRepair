a = list(map(int,input().split()))
wa = 0
wa += a[1]
if a[0] > 0 and a[3] > 0 and a[4] > 0:
  wa = max(wa+(a[0]//2+a[3]//2+a[4]//2)*2,wa+3+((a[0]-1)//2+(a[3]-1)//2+(a[4]-1)//2)*2)
else:
  wa = wa+(a[0]//2+a[3]//2+a[4]//2)*2
print(wa)