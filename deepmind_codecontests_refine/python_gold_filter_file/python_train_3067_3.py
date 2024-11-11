n=int(input())
species=[]
colour=[]
list1=[]
for i in range(n):
	content=input().split()
	species.append(content[0])
	colour.append(content[1])
'''print(species)
print(colour)'''
count=1

for i in range(n):
	list1.append(species[i]+'+'+colour[i])
count=len(set(list1))
print(count)
