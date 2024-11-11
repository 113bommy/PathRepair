c= list(map(int,input().split()))
c2 = list(map(int,input().split()))
fr = 0
ne = 0
for i in range(0,3):
    if c[i] > c2[i]:
        fr+= (c[i] - c2[i])//2
    elif c[i]< c2[i]:
        ne+=c2[i] - c[i]
if fr >= ne:
    print('Yes')
else:
    print('No')

        
