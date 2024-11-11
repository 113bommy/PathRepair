def listToString(s):  
    
    # initialize an empty string 
    str1 = ""  
    
    # traverse in the string   
    for ele in s:  
        str1 += ele   
    
    # return string   
    return str1


n=int(input())
str=input()
l=['a','e','i','o','u','y']
i=0
while(i<len(str)-1):
    if((str[i] in l) and (str[i+1] in l)):
        nstr=[]
        for j in range(len(str)):
            if(j==i+1):
                continue
            else:
                nstr.append(str[j])
        str=listToString(nstr)
        i=i+2
        if(i>=len(str)-1):
            for r in range(len(str)-1):
                if((str[r] in l) and (str[r+1] in l)):
                    i=0
    else:
        i=i+1
        if(i>=len(str)-1):
            for r in range(len(str)-1):
                if((str[r] in l) and (str[r+1] in l)):
                    i=0
            
print(str)
