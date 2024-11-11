n=int(input())

score=0
div2_max=-100000000
only_div1=1
div=0
change=0
contest=[(0,0)]*(n+5) #div, score


for i in range(1,n+1):
    c,d=map(int,input().split())
    only_div1 &= (d==1)
    
    if div==1 and d==2 and change>=0:
        print('Impossible')
        exit()
    if div==2 and d==1 and change<=0:
        print('Impossible')
        exit()

    contest[i-1]=(d,score)
        
    if d==2:
        div2_max=max(div2_max,score)
        
    score+=c
    change=c
    div=d

for i in range(n):
    if contest[i][0]==2 and contest[i][1]>div2_max:
        print('Impossible')
        exit()
    if contest[i][0]==1 and contest[i][1]<=div2_max:
        print('Impossible')
        exit()

if only_div1:
    print('Infinity')
else:
    print(score+(1899-div2_max))
