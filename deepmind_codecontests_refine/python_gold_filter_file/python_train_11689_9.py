numR = int(input())
r1,s1,p1 = [int(x) for x in input().split()] 
r2,s2,p2 = [int(x) for x in input().split()] 

mx,mn = 0,0


mx+=min(r1,s2)
mx+=min(s1,p2)
mx+=min(p1,r2)
mn = max(mn,r1+s2-numR)
mn = max(mn,s1+p2-numR)
mn = max(mn,p1+r2-numR)
print(mn,mx)