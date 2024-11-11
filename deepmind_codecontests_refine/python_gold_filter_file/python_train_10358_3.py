def cal(n,c):
    #print(*n)
    if(c==1):return sum(n)
    elif (c==2):return (n[0]*n[1]*n[2]*n[3])
    elif (c == 3): return (n[0]*(n[1]+n[2]+n[3]))
    elif (c == 4):return (n[0] * n[1]) + n[2]+n[3]
    elif (c == 5): return ((n[0]*n[1])+n[2]+n[3])
    elif (c == 6): return (n[2]+n[3])*(n[0]*n[1])
    elif (c == 7): return ((n[1]*n[2])+n[3])*n[0]
    elif (c == 8) : return (n[0]*n[3])+(n[2]*n[1])
ls=sorted(list(map(int,input().split())))
cd=input()
dic={"+ + +":1,"* * *":2,"+ + *":3,"+ * +":4,"* + +":5,"+ * *":6,"* + *":7,"* * +":8}
print(cal(ls,dic[cd]))