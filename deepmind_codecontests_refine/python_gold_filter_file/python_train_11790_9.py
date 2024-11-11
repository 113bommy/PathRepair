from sys import stdin,stdout
t=int(stdin.readline())
for _ in range(t):
    n=int(stdin.readline())
    dict={}
    temp=0
    left_list=[]
    for i in range(1,n+1):
        dict[i]=0
    for i in range(n):
        list=[int(x) for x in stdin.readline().split()]
        list=list[1:]
        min=9999999
        for j in list:
            if dict[j]==0:
                if j<min:
                    min=j
        if min!=9999999:
            dict[min] = 1
        else:
            left_list.append(i+1)
            temp=1
    if temp==0:
        stdout.write("OPTIMAL"+"\n")
        continue
    stdout.write("IMPROVE"+"\n")
    for i in dict:
        if dict[i]==0:
            temp=i
            break
    stdout.write(str(left_list[0])+" "+str(temp)+"\n")