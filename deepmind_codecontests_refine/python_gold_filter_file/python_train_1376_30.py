t=int(input())
lis=[]
for i in range(t):
    n=[]
    a=input()
    if a[-5:].find("po")!=-1:
        print("FILIPINO")
    elif a[-5:].find("desu")!=-1 or a[-5:].find("masu")!=-1:
        print("JAPANESE")
    elif a[-5:].find("mnida")!=-1:
        print("KOREAN")