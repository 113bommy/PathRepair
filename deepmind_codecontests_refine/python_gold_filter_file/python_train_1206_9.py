def isSubSequence(str1,str2): 
    m , n, i, j= len(str1) ,len(str2) , 0, 0
    while j<m and i<n:
        if str1[j] == str2[i]:     
            j = j+1    
        i = i + 1
    return j==m 

str1 = "heidi"
str2 = input()
  
if isSubSequence(str1,str2):
    print("YES")
else:
    print("NO")