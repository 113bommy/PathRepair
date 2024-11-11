#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# http://codeforces.com/problemset/problem/401/C

n,m = map(int,input().split())
if m>2*(n+1) or m<n-1:
    print("-1")
    exit()

string = ""
while m>n and n!=0:
    string+="110"
    m-=2
    n-=1

while n>0 and m>0:
    string+="10"
    m-=1
    n-=1

if m>0:
    string+="1"*m
elif n>0:
    string="0"+string
print(string)