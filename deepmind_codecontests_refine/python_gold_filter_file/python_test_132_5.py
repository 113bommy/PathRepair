t=int(input())
a=[]
b=[0,0,0]
x=0
y=0
z=0
temp=0
for i in range (0,t):
    a1,a2,a3,a4,a5,a6,a7=input().split()
    a.insert(0,int(a1))
    a.insert(1,int(a2))
    a.insert(2,int(a3))
    a.insert(3,int(a4))
    a.insert(4,int(a5))
    a.insert(5,int(a6))
    a.insert(6,int(a7))


    sum_bc=a[6]-a[0]
    b.insert(0,a[0])
    for j in range (1,6):
        #print("i)
        if j!=1 and a[j]+a[1]==sum_bc:
            #print("1:"+str(j)+" "+str(a[j]))
            b.insert(1,a[1])
            b.insert(2,a[j])
            break
        if j!=2 and a[j]+a[2]==sum_bc:
            #print("2:"+str(j)+" "+str(a[j]))
            b.insert(1,a[2])
            b.insert(2,a[j])
            break
        if j!=3 and a[j]+a[3]==sum_bc:
            #print("3:"+str(j)+" "+str(a[j]))
            b.insert(1,a[3])
            b.insert(2,a[j])
            break
        if j!=4 and a[j]+a[4]==sum_bc:
            #print("4:"+str(j)+" "+str(a[j]))
            b.insert(1,a[4])
            b.insert(2,a[j])
            break
        if j!=5 and a[j]+a[5]==sum_bc:
            #print("5:"+str(j)+" "+str(a[j]))
            b.insert(1,a[5])
            b.insert(2,a[j])
            break
    #print("result")
    print(*b[0:3],sep=" ")
