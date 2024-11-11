import operator

n = int(input())

kuro = input()
shiro = input()
katie = input()

dict_of_res = {'kuro':{}, 'shiro':{}, 'katie':{}}
lenght = len(kuro)
for s in range(0, len(kuro)):

    # import pdb; pdb.set_trace()
    if kuro[s] in dict_of_res['kuro'].keys():
        dict_of_res['kuro'][kuro[s]] += 1
    elif kuro[s] not in dict_of_res['kuro'].keys():
        dict_of_res['kuro'][kuro[s]] = 1

    if shiro[s] in dict_of_res['shiro'].keys():
        dict_of_res['shiro'][shiro[s]] += 1
    elif shiro[s] not in dict_of_res['shiro'].keys():
        dict_of_res['shiro'][shiro[s]] = 1

    if katie[s] in dict_of_res['katie'].keys():
        dict_of_res['katie'][katie[s]] += 1
    elif katie[s] not in dict_of_res['katie'].keys():
        dict_of_res['katie'][katie[s]] = 1

dict_of_res['kuro'] = sorted(dict_of_res['kuro'].items(), key=operator.itemgetter(1), reverse=True)
dict_of_res['shiro'] = sorted(dict_of_res['shiro'].items(), key=operator.itemgetter(1), reverse=True)
dict_of_res['katie'] = sorted(dict_of_res['katie'].items(), key=operator.itemgetter(1), reverse=True)


max_dict = {'kuro':[], 'shiro':[], 'katie':[]}

if (n>lenght):
    print('Draw')
    exit()

for pair in dict_of_res['kuro']:
    if pair[1] not in max_dict['kuro']:
        temp_l = lenght-pair[1]
        temp = None
        temp_n = n
        if n==1 and temp_l == 0:
            temp = lenght-1
        elif temp_l <= n:
            temp = lenght
        else:
            temp = (pair[1] + n)

        max_dict['kuro'].append(temp)
    if len(max_dict['kuro']) == 1:
        break
for pair in dict_of_res['shiro']:
    if pair[1] not in max_dict['shiro']:
        temp_l = lenght - pair[1]
        temp = None
        temp_n = n
        if n==1 and temp_l == 0:
            temp = lenght-1
        elif temp_l <= n:
            temp = lenght
        else:
            temp = (pair[1] + n)

        max_dict['shiro'].append(temp)
    if len(max_dict['shiro']) == 1:
        break
for pair in dict_of_res['katie']:
    if pair[1] not in max_dict['katie']:
        temp_l = lenght - pair[1]
        temp = None
        temp_n = n
        if n==1 and temp_l == 0:
            temp = lenght-1
        elif temp_l <= n:
            temp = lenght
        else:
            temp = (pair[1] + n)

        max_dict['katie'].append(temp)
    if len(max_dict['katie']) == 1:
        break

maxr_dict = {}
for k, v in max_dict.items():
    maxr_dict[k] = max(v)
same = False


ma_t = max(maxr_dict.items(), key=operator.itemgetter(1))[0]
ma_v = max(maxr_dict.items(), key=operator.itemgetter(1))[1]
if (maxr_dict['kuro'] == maxr_dict['shiro'] and maxr_dict['shiro']==ma_v) or \
        (maxr_dict['kuro'] == maxr_dict['katie'] and maxr_dict['katie']==ma_v) or \
        (maxr_dict['katie'] == maxr_dict['shiro'] and maxr_dict['shiro']==ma_v):
    same = True

if same:
    print('Draw')
else:
    print(ma_t.capitalize())