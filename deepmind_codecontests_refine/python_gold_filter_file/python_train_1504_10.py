n=int(input())
l,r=-1998638045,11**11
for _ in range(n):
    lr,x,yn=input().split()
    x=int(x)
    if yn=='Y':
        if lr=='>':
            if x+1>l: l=x+1
        elif lr=='<':
            if x-1<r: r=x-1
        elif lr=='>=':
            if x>l: l=x
        else:
            if x<r: r=x
    else:
        if lr=='>':
            if x<r: r=x
        elif lr=='<': 
            if x>l: l=x
        elif lr=='>=':
            if x-1<r: r=x-1
        else:
            if x+1>l: l=x+1        
if l>r: print('Impossible')
else: print(l)