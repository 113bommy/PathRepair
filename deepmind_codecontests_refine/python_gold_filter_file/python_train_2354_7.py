def main():
    t = int(input())
    l = list(map(int,input().split(None,t)[:t]))
    i = 0
    j = 0
    for x in l:
        if(x%2!=0):
            i+=1
        else:
            j+=1
    if((i%2!=0) or (i%2==0 and i-1!=0) and(i!=0)):
       print("First")
    else:
        print("Second")


        

if __name__=="__main__":
    main()
    
    
