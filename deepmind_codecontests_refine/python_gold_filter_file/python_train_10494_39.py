N,A,B,C,D = list(map(lambda x: int(x),input().split()))
S = " "+input()
def isAble():
    if "##" in S[A:C+1] or "##" in S[B:D+1]:
        return "No"
    if C>D:
        if "..." not in S[B-1:D+2]:
            return "No"
    return "Yes"

print(isAble())