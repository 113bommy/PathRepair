for _ in range(int(input())):
    n=int(input())
    if(n<=3):
        print(-1)
    else:
        if(n%2==0):
            l=[i for i in range(1,n+1)]
            l1=[n-1]
            l.remove(n-1)
        else:
            l=[i for i in range(1,n)]
            l1=[n]   
        l.sort()
        l.reverse()
        front=0
        top=0
        count=0
        d=len(l)-1
        m=0
        while(count!=d):
            if(front>len(l)-1):
                m=1
                break
            if(2<=abs(l1[top]-l[front])<=4):
                l1.append(l[front])
                l.remove(l[front])
                front=0
                top+=1
                count+=1
            else:
                front+=1
        if(m==1):
            l.sort()
            l.reverse()
            for i in range(0,len(l1)-1):
                if(2<=abs(l1[i]-l[0])<=4 and 2<=abs(l1[i+1]-l[0])<=4):
                    l3=l1[0:i+1]+[l[0]]+l1[i+1:]
                    c=1
                    break
                elif(abs(l[0]-l1[0])<=4 and abs(l[0]-l1[0])>=2):
                    l3=[l[0]]+l1
                    break
                elif(abs(l[0]-l1[len(l1)-1])<=4 and abs(l[0]-l1[len(l1)-1])>=2):
                    l3=l1+[l[0]]
                    break
            for i in range(0,len(l1)-1):
                if(2<=abs(l3[i]-l[1])<=4 and 2<=abs(l3[i+1]-l[1])<=4):
                    l3=l3[0:i+1]+[l[1]]+l3[i+1:]
                    break
                elif(abs(l[1]-l3[0])<=4 and abs(l[1]-l3[0])>=2):
                    l3=[l[1]]+l3
                    break
                elif(abs(l[1]-l3[len(l3)-1])<=4 and abs(l[1]-l3[len(l3)-1])>=2):
                    l3=l3+[l[1]]
                    break
            print(*l3)
        else:
            for i in range(0,len(l1)-1):
                if(2<=abs(l1[i]-l[0])<=4 and 2<=abs(l1[i+1]-l[0])<=4):
                    l3=l1[0:i+1]+[l[0]]+l1[i+1:]
                    break
                elif(abs(l[0]-l1[0])<=4 and abs(l[0]-l1[0])>=2):
                    l3=[l[0]]+l1
                    break
                elif(abs(l[0]-l1[len(l1)-1])<=4 and abs(l[0]-l1[len(l1)-1])>=2):
                    l3=l1+[l[0]]
                    break
            print(*l3)
        
        
