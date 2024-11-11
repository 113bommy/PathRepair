if __name__=="__main__":
    n=int(input())
    li=[]
    ma = []
    for i in range(n):
        r=input()
        li.append(r)
    for i in range(n):
        c=0
        if li[i][0]=="+":
            c=c+1
        else:
            temp=li[i]
            temp='+'+temp[1:]
            if temp not in li[0:i]:
                c=c+1
        for j in range(0,i):
            if li[j][0] == "+":
                temp = li[j]
                temp = '-' + temp[1:]
                if temp not in li[j+1:i]:
                    c = c + 1
        for k in range(i+1,n):
            if li[k][0]=='-':
                temp = li[k]
                temp = '+' + temp[1:]
                if temp not in li[0:k]:
                    c = c + 1
        ma.append(c)
    print(max(ma))






