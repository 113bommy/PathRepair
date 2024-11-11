from collections import Counter
N = int(input())
List = [int(x) for x in input().split()]
Dict = Counter(List)
Counts = list(Dict.values())
n = len(Counts)
One = Counts.count(1)
if(One  % 2 == 0): # Completed
    # Go Normal
    flip = 0
    print("YES")
    Ans = ""
    for i in range(N):
        if(Dict[List[i]] == 1):
            Ans += chr(65 + flip)
            flip^=1
        else:
            Ans+="A"
    print(Ans)
else:
    notDecided = -1
    flip = 0
    Ans = ""
    for i in range(N):
        if(Dict[List[i]] == 1):
            Ans += chr(65 + flip)
            flip^=1
        elif(Dict[List[i]] != 2 and notDecided == -1):
            notDecided = Dict[List[i]] 
            Ans += "B"
        elif(Dict[List[i]] % 2 != 0 and Dict[List[i]] == notDecided):
            Ans += "A"
        else:
            Ans += "A"
    if(notDecided == -1):
        print("NO")
    else:
        print("YES")
        print(Ans)


