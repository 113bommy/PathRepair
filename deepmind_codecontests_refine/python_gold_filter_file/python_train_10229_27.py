#!/usr/bin/env python
# coding: utf-8

# In[2]:


t = int(input())
for i in range(t):
    abn = list(map(int, input().split(" ")))
    a = None
    b = None
    count = 0
    if(abn[0]> abn[1]):
        a = abn[0]
        b = abn[1]
    else:
        a = abn[1]
        b = abn[0]
    while(a<=abn[2] and b<=abn[2]):
        b += a
        a += b
        count += 2
    if(a> abn[2] and b>abn[2]):
        print((count-1))
    else:
        print(count)
        
    





