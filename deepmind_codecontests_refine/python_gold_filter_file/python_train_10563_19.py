def main():
    n,m=map(int,input().split())
    li=[]
    while(m>0):
        a,b=input().split()
        li.append((a,b))
        m-=1
    di=dict(li)
    li1=list(input().split())
    for i in li1:
        if(len(i)<=len(di[i])):
            print(i,end=" ")
        else:
            print(di[i],end=" ")
main()