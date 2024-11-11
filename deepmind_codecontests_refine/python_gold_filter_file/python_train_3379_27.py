n=int(input())
s1,s2=input().split(),input().split()
print("I become the guy." if len(set(s1[1:]+s2[1:]))==n else "Oh, my keyboard!")