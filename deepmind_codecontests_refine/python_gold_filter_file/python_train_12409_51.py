ch=input().split()
def l(string):
    b=[]
    for i in string:
        if i not in b:
            b.append(i)
    return b
def do():
    for i in range(int(ch[0]),int(ch[1])+1):
        if [x for x in str(i)] == l(str(i)):
            print(i)
            return
            
    print(-1)
do()