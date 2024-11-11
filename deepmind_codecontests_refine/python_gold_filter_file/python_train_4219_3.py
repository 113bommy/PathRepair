def answer():
    n = int(input())
    m = int(input())
    c=[]
    while n:
        c.append(int(input()))
        n-=1
    c.sort()
    c.reverse()
    i=0
    while i<len(c):
        m-=c[i]
        if m<=0:
            print(i+1)
            break
        i+=1
answer()
