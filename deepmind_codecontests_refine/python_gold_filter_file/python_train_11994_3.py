for _ in range(int(input())):
   s = list(input())
   l = len(s)
   flag = True
   if l == 1 :
       print('a')
       flag = False
       continue
   
   for i in range(l):
       flag = True
       
       if i !=0 and i != l-1 and s[i] != '?' and (s[i] == s[i+1] or s[i] == s[i-1]):
           print(-1)
           flag = False
           break
       elif i==0 and s[i] != '?' and s[i] == s[i+1] :
           print(-1)
           flag = False
           break
       elif i==l-1 and s[i] != '?' and s[i] == s[i-1] :
           print(-1)
           flag = False
           break
           
       else :
           
           if s[i] == '?' : 
               
               if i == 0 :
                   
                   if s[i+1] == 'a' :
                       s[i] = 'b'
                       continue
                   if s[i+1] == 'b' :
                       s[i] = 'c'
                       continue
                   if s[i+1] == 'c' or s[i+1] == '?' :
                       s[i] = 'a'
                       continue
                   
               elif i == l-1 :
                   
                   if s[i-1] == 'a' :
                       s[i] = 'b'
                       continue
                   if s[i-1] == 'b' :
                       s[i] = 'c'
                       continue
                   if s[i-1] == 'c' :
                       s[i] = 'a'
                       continue
            
               else :
                   
                   if s[i-1] == 'a' and (s[i+1] == 'a' or s[i+1] == 'c' or s[i+1] == '?') :
                       s[i] = 'b'
                       continue
                   if s[i-1] == 'a' and (s[i+1] == 'b' or s[i+1] == '?') :
                       s[i] = 'c'
                       continue
                  
                   
                   if s[i-1] == 'b' and (s[i+1] == 'a' or s[i+1] == '?') :
                       s[i] = 'c'
                       continue
                   if s[i-1] == 'b' and (s[i+1] == 'b' or s[i+1] == 'c' or s[i+1] == '?') :
                       s[i] = 'a'
                       continue
                   
                    
                   if s[i-1] == 'c' and (s[i+1] == 'b' or s[i+1] == '?') :
                       s[i] = 'a'
                       continue
                   if s[i-1] == 'c' and (s[i+1] == 'c' or s[i+1] == 'a' or s[i+1] == '?') :
                       s[i] = 'b'
                       continue 
    
    
   if flag :        
       print(''.join(s))