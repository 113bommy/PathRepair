#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#输入行数
line=int(input())
#输入每行的人名和得分
room=[]
i=0
while i<line:
	room.append(list(input().split()))
	room[i][1]=int(room[i][1])
	i=i+1
#构建人名表
name={}
i=0
while i<line:
	if room[i][0] not in name:
		name[room[i][0]]=0
	i=i+1
#算出末尾分
i=0
while i<line:
	name[room[i][0]]=name[room[i][0]]+room[i][1]
	i=i+1
#算出末尾分最早在哪里到达(再跑一次)
name1={}
i=0
while i<line:
	if room[i][0] not in name1:
		name1[room[i][0]]=0
	i=i+1
name2={}
i=0
while i<line:
	if room[i][0] not in name2:
		name2[room[i][0]]=line+1
	i=i+1
i=0
while i<line:
	name1[room[i][0]]=name1[room[i][0]]+room[i][1]
	if name1[room[i][0]]>name[room[i][0]] or name1[room[i][0]]==name[room[i][0]]:
		if name2[room[i][0]]>i:
			name2[room[i][0]]=i
	i=i+1
#开始比
p=name[room[0][0]]
q=name2[room[0][0]]
r=room[0][0]
for str in name:
	if name[str]>p:
		p=name[str]
		q=name2[str]
		r=str
	if name[str]==p and name2[str]<q:
		p=name[str]
		q=name2[str]
		r=str
print(r)