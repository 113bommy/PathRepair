# -*- coding: utf-8 -*-
"""
Created on Thu Oct 22 16:37:25 2015

@author: kevin
"""

#O(n)

taille=int(input())
tableausolution=input()
tabs=tableausolution.split(" ")
#j'ai le tab sous forme de ['1','2']
dico={}
for i in range(taille):
	tabs[i]=int(tabs[i])
	try:
		dico[tabs[i]][1]=i
		dico[tabs[i]][2]+=1
	
	except:
		dico[tabs[i]]=[i,i,1]

maxi=0
maxii=0
for i in dico.keys():
	res=dico[i]
	if(res[2]>maxi):
		maxi=res[2]
		maxii=i
	elif(res[2]==maxi):
		if((res[1]-res[0])<(dico[maxii][1]-dico[maxii][0])):
			maxi=res[2]
			maxii=i
		
print (dico[maxii][0]+1,dico[maxii][1]+1)		
	
	