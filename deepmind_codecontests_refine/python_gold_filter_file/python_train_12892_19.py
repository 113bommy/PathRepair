N = int(input())
S1 = input()
S2 = input()
 
result = 3
if N != 1:
    i=1
    while i < N:
        if i==1:
            result *= 2
        elif S1[i-1]==S2[i-1]:
            result *=2
        elif S1[i-1]!=S1[i]:
            if S1[i] != S2[i]:
                result *= 3
        i += 1
 
print(result%1000000007) 
