w=sorted(list(input()))+["_"];s="Yes" 
for i in range(1,len(w),2):
    if w[i]!=w[i-1]:s="No"
print(s)