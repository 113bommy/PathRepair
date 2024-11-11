n, m = [int(x) for x in input().split()]
fire_mana, fire_range, bsk_mana = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

i, k = 0, 0
min_mana = 0
last_target = 0
for j in range(n):
    if a[j] == b[k]:
        #solve interval i to j
        enemies = j-i
 #       print("Found", enemies)
        if enemies > 0:
            
            edgepower = max(last_target, b[k])
            max_enemypower = max(a[i:j])
            mana_used = 0
            if max_enemypower > edgepower:
                enemies -= fire_range
                mana_used += fire_mana
            if enemies < 0:
                min_mana = -1
                break
            if fire_mana / fire_range < bsk_mana:
                mana_used += fire_mana * (enemies // fire_range)
                enemies %= fire_range
            mana_used += bsk_mana * enemies
            min_mana += mana_used
#        print("mana used:", min_mana)
        last_target = b[k]
        i = j+1
        k += 1
        if k == m:
            break
if k != m:
    min_mana = -1
if min_mana != -1:
    enemies = n-i
    if enemies > 0:
        edgepower = last_target
        max_enemypower = max(a[i:])
        mana_used = 0
        if max_enemypower > edgepower:
            enemies -= fire_range
            mana_used += fire_mana
        if enemies < 0:
            min_mana = -1
        else:
            if fire_mana / fire_range < bsk_mana:
                mana_used += fire_mana * (enemies // fire_range)
                enemies %= fire_range
            mana_used += bsk_mana * enemies
            min_mana += mana_used
print(min_mana)
