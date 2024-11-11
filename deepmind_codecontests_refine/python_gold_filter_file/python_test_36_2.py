#import sys
#sys.stdin=open('input.txt','r')
#sys.stdout=open('output.txt','w')


def composite(x):
    if(x==2):
        return False
    for i in range(2,x):
        if(x%i)==0:
            return True
    return False





def solve():
    n=int(input())
    l=list(map(int,input().split()))
    pairs=[]
    for i in range(n):
        pairs.append([l[i],i])
    pairs=sorted(pairs)
    x=0
    for i in range(len(l)):
        x+=pairs[i][0]
    #print(x)

    if(composite(x)):
        #print("yed")
        ans=n
        print(ans)
        for i in range(1,n+1):
            print(i,end=" ")
        print()
        return
    else:
        #print(pairs)
        for i in range(len(pairs)):

            y=x-pairs[i][0]
            s=pairs.pop(i)
            #print(pairs)
            #print("x become",y)
            if(composite(y)):
                #print("hrt")
                print(n-1)
                pairs=sorted(pairs,key=lambda x:x[1])
                for j in range(len(pairs)):
                    print(pairs[j][1]+1,end=" ")
                print()
                break
            else:
                pairs.insert(i,s)


















t=int(input())
while(t!=0):
    solve()
    t-=1
