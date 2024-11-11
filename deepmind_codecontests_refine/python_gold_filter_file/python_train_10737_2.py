size = int(input())

def segment(array):
    aux = []
    el = int(array[0])
    count=0
    for i in range(len(array)):
        if int(array[i]) == el:
            count+=1
        else:
            aux.append(count)
            count=1
            el = int(array[i])
    aux.append(count)
    return aux
        
def maxx(array):
    max_ = 0
    for i in range(1, len(array)):
        max_ = max(max_, min(array[i-1], array[i])) 
    return 2*max_  
segments = input().split()
aux = segment(segments)
print(maxx(aux))
        
        
