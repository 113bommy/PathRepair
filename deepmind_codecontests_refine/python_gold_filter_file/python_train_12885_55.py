S = input()
T = input()
 
print(len([x for x in map(set, zip(S, T)) if len(x) == 2]))