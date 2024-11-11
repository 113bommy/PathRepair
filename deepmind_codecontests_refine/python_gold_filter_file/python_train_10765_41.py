n3=int(input())
if(n3==0):
    print("O-|-OOOO")
else:    
    while(n3!=0):
        n1=n3%10
        n3=n3//10
        s1=""
        if(n1<5):
            s1="O-"
        else:
            s1='-O'
            n1=n1-5
        n2=n1
        s1=s1+"|"
        while(n1!=0):
            s1=s1+'O'
            n1-=1
        s1+='-'
        while(4-n2!=0):
            s1=s1+'O'
            n2+=1
        print(s1)    


        