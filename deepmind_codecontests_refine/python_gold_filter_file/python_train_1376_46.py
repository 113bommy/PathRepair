a=int(input())
for i in range(0,a):
    b=input()
    if b.find("po",len(b)-2)>-1:
        print("FILIPINO")
    elif b.find("mnida",len(b)-5)>-1:
        print("KOREAN")
    else:
        print("JAPANESE")
    
    
