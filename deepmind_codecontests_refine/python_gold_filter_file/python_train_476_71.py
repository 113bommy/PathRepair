n,v1,v2,t1,t2 = [int(x) for x in input().split()]
a,b = [(n*v1)+(2*t1),(n*v2)+(2*t2)]
print("First" if a<b else ("Second" if b<a else "Friendship"))