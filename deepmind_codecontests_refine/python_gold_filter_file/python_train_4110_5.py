__author__ = 'pxy'
(a,b,c,d) = (int(i) for i in input().split())
bmish=max(3*a//10,a-(a//250*c))
bvit=max(3*b//10,b-(b//250*d))
if bmish>bvit:
    print('Misha')
else:
    if(bmish==bvit):
        print('Tie')
    else:
        print('Vasya')
