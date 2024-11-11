h,w = map(int,input().split())
if (w == 2 or h == 2):
    print(0)
else:
    print(max(1,h-2)*max(1,w-2))