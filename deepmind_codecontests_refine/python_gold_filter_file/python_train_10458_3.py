def main():
    n=list
    #n=[0,1,1,1,5,9]
    
    n=list(map(int,input().split()))
    for j in range(6):
        for i in range(5):
            if n[i]>n[i+1]:
                a=n[i]
                b=n[i+1]
                n[i]=b
                n[i+1]=a
   
    if n[2]==n[3]:
       
        if int(n[0])-int(n[3])==0 or int(n[5]-n[3])==0:
            
            if int(n[0])-int(n[1])==0 and int(n[5])-int(n[4])==0:
                print("Elephant")
            else:
                print("Bear")
                
                       
        else:
             if int(n[1])-int(n[2])==0 and int(n[3])-int(n[4])==0 and (int(n[5])-int(n[0]))>0:
                 print("Bear")
             else:
                 print("Alien")
    
    else:
        print("Alien")
        
    

  

if __name__=='__main__':
    main()

        
    
