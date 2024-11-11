n=int(input())
garden = list(map(int, input().strip().split()))
answers=[]
if n==1:
    answers.append(1)
else:
    for i in range(0,len(garden)) :
        xleft=[]
        for j in range(i,0,-1):
            if garden[j-1]<=garden[j]:
                xleft.append(garden[j-1])
            else:
                break
        xright=[]
        for k in range(i,len(garden)-1):
            if garden[k+1]<=garden[k]:
                xright.append(garden[k+1])
            else:
                break
        
    
        answers.append( len(xleft)+len(xright)+1 )

print (max(answers))

