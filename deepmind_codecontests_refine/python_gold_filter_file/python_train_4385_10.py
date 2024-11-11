pr,ft,el,tst,tel,t3=map(int,input().split())
t1=abs(pr-ft)*tel + abs(el-pr)*tel 
t2=abs(pr-ft)*tst
#print(t1+3*t3,t2)
if t1+3*t3<=t2 :
    print("YES")
else :
    print("NO")