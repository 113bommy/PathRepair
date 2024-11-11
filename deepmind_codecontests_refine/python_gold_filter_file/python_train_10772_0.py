n,s,t = int(input()),input(),input()

d = {}
wrongs = []
ansD,ansI,ansJ = 0,-1,-1
for i in range(n) :
    if s[i]!=t[i] :
        ansD+=1
        wrongs.append(i)
        d[t[i]] = i

perfectSwapped = False
swapped = False
for i in wrongs :
    if s[i] in d :
        swapped = True
        ansI = i+1
        j = d[s[i]]
        ansJ = j+1
        if s[j]==t[i] :
            perfectSwapped = True
            break

print(ansD-(2 if perfectSwapped else 1 if swapped else 0))
print(ansI, ansJ)
        
