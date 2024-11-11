def solve (pb,eb,pseq,eseq) :
    if pb > eb :
        return "YES"
    elif eb > pb :
        return "NO"
    else :
        pseq.sort()
        eseq.sort()
        
        pIndex = 0
        eIndex = 0
        turn = 0
        
        wordsPB = pb
        wordsEB = eb

        while pIndex < pb and eIndex < eb :
            if pseq[pIndex] == eseq[eIndex] :
                if turn == 0 :
                    wordsEB -= 1
                    turn = 1
                else :
                    wordsPB -= 1
                    turn = 0
                eIndex += 1
                pIndex += 1
            
            elif pseq[pIndex] > eseq[eIndex] :
                eIndex += 1
                
            else :
                pIndex += 1
        
        if wordsEB >= wordsPB :
            return "NO"
        else :
            return "YES"
            
pb , eb = list(map(int,input().split()))
pseq = []
eseq = []
for x in range(pb) :
    pseq.append(input())

for y in range(eb):
    eseq.append(input())
    
print (solve(pb,eb,pseq,eseq))
    
                    
                    
                
                
            
        
        

     
    
    

   