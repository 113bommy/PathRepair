from collections import*
h,*t=open(0)
h,w=map(int,h.split())
f,o=1,0
for i in Counter(''.join(t)).values():
    f+=i//4
    o+=i&1
print('YNeos'[o-h%2>h%2*w%2or f-h//4<=h//2*(w//2)::2])